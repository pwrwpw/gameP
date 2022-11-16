class Snake {
    constructor(ctx) {
        this.ctx = ctx;
        this.spawn();
    }

    spawn() {
        this.color = "green";
        this.position = [
            { x: 4, y: 4 }
        ]
        this.dx = 0;
        this.dy = 0;
        this.speed = 100;
    }

    draw() {
        this.ctx.fillStyle = this.color;
        this.position.forEach((element) => {
            this.ctx.fillRect(element.x, element.y, 1, 1);
        });
    }

    move() {
        const head = { x: this.position[0].x + this.dx, y: this.position[0].y + this.dy };
        if (this.collision(head)) {
            audio.playSFX(DEAD);
            game.gameOver();
        }

        this.position.unshift(head);

        const eat = head.x === game.fruit.x && head.y === game.fruit.y;

        if (eat) {
            game.fruit.random();
            game.updateScore();
            audio.playSFX(FRUIT_EAT);
            if (this.position.length % 5 == 0) {
                game.updateLevel();
                time.level -= this.speed;
                this.speed = Math.log2(this.speed) * 5;
            }
        }
        else {
            this.position.pop();
        }
    }

    collision(head) {
        if (head.x < 0 || head.x >= COLS) {
            return true;
        }
        else if (head.y < 0 || head.y >= ROWS) {
            return true;
        }

        for (var i = 1; i < this.position.length; i++) {
            if (this.position[i].x == head.x && this.position[i].y == head.y) {
                return true;
            }
        }
    }

    setDirection(p) {
        this.dx = p.dx;
        this.dy = p.dy;
    }
}