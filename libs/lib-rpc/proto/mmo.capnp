 @0x808a2538389a6991;
 
struct MoveVector {
    x @0: Int32;
    y @1: Int32;
    z @2: Int32;
}

struct Motion {
    posision @0: MoveVector;
    rotation @1: MoveVector;
    velocity @2: MoveVector;
}

struct Character{
    id @0: Text;
    instanceId @1: Text;
    mapId @2: Text;
    motion @3: Motion;
}

interface RealmBase {
    updateCharacter @0 (character :Character) -> (value :UpdateCharacterValue);
    
    interface UpdateCharacterValue {
        read @0 () -> (value :Bool);
    }
}