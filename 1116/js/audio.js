function AudioPLAY() {
    this.bgm;
    this.sfx;

    this.init = function () {
        this.bgm = new Audio(INTRO);
        this.bgm.loop = true;
        this.sfx = new Array();
        this.sfx[1] = new Audio(FRUIT_EAT);
        this.sfx[2] = new Audio(BUTTON);
        this.sfx[3] = new Audio(DEAD);
    }
    this.playGAMEBGM = function () {
        this.bgm.pause();
        this.bgm.src = GAMEBGM;
        this.bgm.load();
        this.bgm.play();
    }
    this.playOUTRO = function () {
        this.bgm.pause();
        this.bgm.src = OUTRO;
        this.bgm.load();
        this.bgm.play();
    }
    this.playSFX = function (sfx) {
        switch (sfx) {
            case FRUIT_EAT:
                this.sfx[1].play(); break;
            case BUTTON:
                this.sfx[2].play(); break;
            case DEAD:
                this.sfx[3].play(); break;
        }
    }
}