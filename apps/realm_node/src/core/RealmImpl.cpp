#include "RealmImpl.hpp"
#include <iostream>
#include "UpdateCharacterValueImpl.hpp"

kj::Promise<void> RealmImpl::updateCharacter(UpdateCharacterContext context)
{
    auto extCharacter = context.getParams().getCharacter();
    auto local = mCharactersHash.find(extCharacter.getId());
    if (local == mCharactersHash.end())
    {
        game::Character localChar(extCharacter.getId(), extCharacter.getInstanceId(), "", {{"map"}, {0,0,0},{0,0,0},{0,0,0}});
        mCharactersHash.insert({extCharacter.getId(), localChar});
    }
    else 
    {
        game::Character localChar(extCharacter.getId(), extCharacter.getInstanceId(), "", {{"map"}, {0,0,0},{0,0,0},{0,0,0}});
        mCharactersHash[extCharacter.getId()] =  localChar;
    }
    std::cout << "Received Request on Character Update" << std::endl;
    context.getResults().setValue(kj::heap<UpdateCharacterValueImpl>(true));
    return kj::READY_NOW;
}