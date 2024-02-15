#include "WorkingContext.hpp"
#include <boost/bind.hpp>
#include <iostream>

using boost::asio::steady_timer;

WorkingContext::WorkingContext()
    : context_{}
    , idleWork_{context_}
    , workingThread_{boost::bind(&boost::asio::io_service::run, &context_)}
{

}

WorkingContext::~WorkingContext() {
    context_.stop();
    if (workingThread_.joinable()) {
        workingThread_.join();
    }
}

std::function<void()> WorkingContext::task_wrapper_(ContextTask context_task) {
	const auto task_post_time = std::chrono::system_clock::now();
	auto task = [this, context_task, task_post_time](){
		const auto task_exec_start = std::chrono::system_clock::now();
		context_task.task();
		auto task_exec_end = std::chrono::system_clock::now();
		queue_cnt_--;
		const auto task_exec_duration = task_exec_end - task_exec_start;
		const auto task_start_delay = task_exec_start - task_post_time;
		if (context_task.display) {
			std::cout << "Task " << context_task.name
															<< ", Duration: "
															<< std::chrono::duration_cast<std::chrono::microseconds>(
																	task_exec_duration).count()
															<< " microseconds, Start Delay: "
															<< std::chrono::duration_cast<std::chrono::microseconds>(
																	task_start_delay).count()
															<< " microseconds, Tasks in queue left: " << queue_cnt_ << std::endl;
		}
	};
	return task;
}

void WorkingContext::post(ContextTask context_task) {
	queue_cnt_++;
    context_.post(task_wrapper_(context_task));
}

void WorkingContext::postWithDelay(ContextTask context_task, std::chrono::milliseconds delay_ms) {
    auto delay_timer = std::make_shared<boost::asio::steady_timer>(context_);
    delay_timer->expires_from_now(delay_ms);
	auto task = task_wrapper_(context_task);
	queue_cnt_++;
    delay_timer->async_wait([task, delay_timer](const boost::system::error_code& error){
        if (!error) {
			task();
        }
    });
}
