#include "mmo.capnp.h"

class UpdateCharacterValueImpl final: public RealmBase::UpdateCharacterValue::Server
{
public:
  UpdateCharacterValueImpl(bool value);
  kj::Promise<void> read(ReadContext context);

private:
  bool value;
};