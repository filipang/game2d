
function run() {

    var doorPos = getDoorPos();
    var npcPos = getNpcPos();
    print("door at: " + doorPos + " and me at: " + npcPos + " ... me moving ... \n");

    if (doorPos < npcPos)
        doNpcMove(-1);
    else doNpcMove(1);
}