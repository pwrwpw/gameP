let menuBtn = document.querySelector("#menu-card button");
let gameMenu = document.getElementById("game-menu");
let endScore = document.getElementById("end-score");
menuBtn.addEventListener("click", clickEvent);
window.onload = function () {
    audio = new AudioPLAY();
    audio.init();
    window.setTimeout(() => {
        let promise = audio.bgm.play();

        if (promise !== undefined) {
            promise.then(_ => {
                promise;
            }).catch(error => {
            });
        }
    }, 650);
}


function clickEvent() {
    gameMenu.style.display = 'none';
    audio.bgm.pause();
    audio.playSFX(BUTTON);
    audio.playGAMEBGM();
    play();
}