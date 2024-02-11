#include "RealmImpl.hpp"
#include <iostream>
#include "UpdateCharacterValueImpl.hpp"

kj::Promise<void> RealmImpl::updateCharacter(UpdateCharacterContext context)
{
    auto extCharacter = context.getParams().getCharacter();
    auto local = mCharactersHash.find(extCharacter.getId());
    if (local == mCharactersHash.end())
    {
        game::XYZVector pos(0,0,0);
        game::XYZVector rot(0,0,0);
        game::XYZVector vel(0,0,0);

        game::Motion motion(std::string("extCharacter."), pos, rot, vel);
        game::Character localChar(extCharacter.getId(), extCharacter.getInstanceId(), "", motion);
        mCharactersHash.insert({extCharacter.getId(), localChar});
    }
    else 
    {
        //mCharactersHash[extCharacter.getId()] =  extCharacter;
    }
    std::cout << "Received Request on Character Update" << std::endl;
    context.getResults().setValue(kj::heap<UpdateCharacterValueImpl>(true));
    return kj::READY_NOW;
}