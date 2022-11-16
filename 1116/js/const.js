const COLS = 10;
const ROWS = 10;
const BLOCK_SIZE = 30;
const KEY = {
    LEFT: 37,
    UP: 38,
    RIGHT: 39,
    DOWN: 40
};
const FRUIT_EAT = './sfx/eat-sfx.wav';
const BUTTON = './sfx/button-sfx.mp3';
const DEAD = './sfx/dead.wav';
const GAMEBGM = './bgm/game-bgm.wav';
const INTRO = './bgm/intro.mp3';
const OUTRO = './bgm/outro.mp3';
let highScore = window.localStorage.getItem("highScore") || undefined;

