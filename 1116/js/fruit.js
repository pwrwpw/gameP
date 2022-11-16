class Fruit {
    constructor(ctx) {
        this.ctx = ctx;
        this.spawn();
        this.random();
    }
    spawn() {
        this.x = 0;
        this.y = 0;
    }

    draw() {
        this.ctx.fillStyle = `rgb(${this.r},${this.g},${this.b})`;
        this.ctx.fillRect(this.x, this.y, 1, 1);
    }

    random() {
        this.r = Math.random() * 255;
        this.g = Math.random() * 255;
        this.b = Math.random() * 255;
        this.x = Math.floor(Math.random() * (COLS));
        this.y = Math.floor(Math.random() * (ROWS));
    }
}