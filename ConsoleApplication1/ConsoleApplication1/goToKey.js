
function run() {

    var keyPos = getKeyPos();
    var npcPos = getNpcPos();
    print("key at: " + keyPos + " and me at: " + npcPos + " ... me moving ... \n");

    if (keyPos < npcPos)
        doNpcMove(-1);
    else doNpcMove(1);
}