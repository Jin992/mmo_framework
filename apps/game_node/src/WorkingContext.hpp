#ifndef WORKINGCONTEXT_HPP
#define WORKINGCONTEXT_HPP

#include <chrono>
#include <functional>
#include <thread>
#include <boost/asio.hpp>


class WorkingContext {
public:
	typedef struct {
		std::string name;
		bool display;
		std::function<void()> task;
	} ContextTask;

    WorkingContext();
    ~WorkingContext();
    void post(ContextTask task);
    void postWithDelay(ContextTask task, std::chrono::milliseconds delay_ms);

private:
	std::function<void()> task_wrapper_(ContextTask task);

private:
    boost::asio::io_service context_;
    boost::asio::io_service::work idleWork_;
    std::thread workingThread_;
	std::size_t queue_cnt_ = 0;
};

#endif // WORKINGCONTEXT_HPP
