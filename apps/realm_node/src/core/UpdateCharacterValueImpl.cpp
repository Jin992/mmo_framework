#include "UpdateCharacterValueImpl.hpp"

UpdateCharacterValueImpl::UpdateCharacterValueImpl(bool value)
: value(value)
{}

kj::Promise<void> UpdateCharacterValueImpl::read(ReadContext context)
{
    context.getResults().setValue(value);
    return kj::READY_NOW;
}
