
function run()
{
    if (npcHasKey()) {
        print("select: I has key ...\n");
        setJustExit(true);
        return;
    }
    print("select: I don't has key ...\n");
    var keyPos = getKeyPos();
    var npcPos = getNpcPos();
    if (keyPos == npcPos) {
        setTrueOrFalse(true);
        return;
    }
}