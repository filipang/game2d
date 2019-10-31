
function run()
{
    if (isDoorOpen()) {
        print("select: Door already open  ...\n");
        setJustExit(true);
        return;
    }
    if (!npcHasKey()) {
        print("select: Don t has key, can t open!\n");
        setJustExit(true);
        return;
    }
    print("select: Door not yet open ...\n");
    var doorPos = getDoorPos();
    var npcPos = getNpcPos();
    if (doorPos == npcPos) {
        setTrueOrFalse(true);
        return;
    }
}