#include "mmo.capnp.h"
#include <unordered_map>
#include <string>
#include "game/Character.hpp"

class RealmImpl final: public RealmBase::Server
{
public:
    kj::Promise<void> updateCharacter(UpdateCharacterContext context) final;
    kj::Promise<void> getNearestCharacters(GetNearestCharactersContext context) final;

private:
    std::unordered_map<std::string, game::Character> mCharactersHash;
};