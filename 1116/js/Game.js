class Game {
    constructor(ctx) {
        this.ctx = ctx;
        this.init();
    }
    init() {
        ctx.canvas.width = COLS * BLOCK_SIZE;
        ctx.canvas.height = ROWS * BLOCK_SIZE;
        ctx.scale(BLOCK_SIZE, BLOCK_SIZE);
    }

    draw() {
        this.drawGame();
        this.fruit.draw();
        this.snake.draw();
    }

    drawGame() {
        this.grid.forEach((row, y) => {
            row.forEach((value, x) => {
                if (value > 0) {
                    this.ctx.fillStyle = COLORS[value];
                    this.ctx.fillRect(x, y, 1, 1);
                }
            });
        });
    }

    gameOver() {
        let score = document.getElementById('score').innerText;
        score = parseInt(score);
        highScore ? null : (highScore = score);
        score > highScore ? (highScore = score) : null;
        window.localStorage.setItem("highScore", highScore);
        menuBtn.innerText = "ReStart";
        document.querySelector("#game-menu h1").innerText = "END";
        document.getElementById('Highscore').innerText = highScore;
        document.getElementById('ENDSCORE').innerText = score;
        gameMenu.style.display = 'flex';
        endScore.style.display = 'flex';
        this.reset();
        audio.playOUTRO();
    }

    updateScore() {
        let score = document.getElementById('score').innerText;
        score = parseInt(score);
        score += 10;
        document.getElementById('score').innerText = score;
    }

    updateLevel() {
        let level = document.getElementById('level').innerText;
        level = parseInt(level);
        level += 1;

        document.getElementById('level').innerText = level;
    }
    resetScore() {
        let score = document.getElementById('score').innerText;
        score = parseInt(score);
        score = 0;

        document.getElementById('score').innerText = score;
    }
    resetLevel() {
        let level = document.getElementById('level').innerText;
        level = parseInt(level);
        level = 0;

        document.getElementById('level').innerText = level;
    }

    reset() {
        time.level = 300;
        this.resetScore();
        this.resetLevel();
        this.grid = this.getEmptyGrid();
        this.snake = new Snake(this.ctx);
        this.fruit = new Fruit(this.ctx);
    }
    getEmptyGrid() {
        return Array.from({ length: ROWS }, () => Array(COLS).fill(0));
    }
}