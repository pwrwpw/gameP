const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');
let game = new Game(ctx);
const moves = {
  [KEY.LEFT]: (p) => ({ ...p, dx: -1, dy: 0 }),
  [KEY.RIGHT]: (p) => ({ ...p, dx: 1, dy: 0 }),
  [KEY.DOWN]: (p) => ({ ...p, dx: 0, dy: 1 }),
  [KEY.UP]: (p) => ({ ...p, dx: 0, dy: -1 })
};

function play() {
  resetGame();
  addEventListener();
  animate();
}

function resetGame() {
  game.reset();
}

let time = { start: 0, elapsed: 0, level: 300 };

function animate(now = 0) {
  time.elapsed = now - time.start;

  if (time.elapsed > time.level) {
    time.start = now;

    game.snake.move();
  }

  ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
  game.draw();

  requestAnimationFrame(animate);
}

function addEventListener() {
  document.removeEventListener('keydown', handleKeyPress);
  document.addEventListener('keydown', handleKeyPress);
}

function handleKeyPress(event) {
  if (moves[event.keyCode]) {
    event.preventDefault();

    let p = moves[event.keyCode](game.snake);

    if (valid(p)) {
      game.snake.setDirection(p);
    }
  }
}

function valid(p) {
  const x = game.snake.dx != -p.dx;
  const y = game.snake.dy != -p.dy;
  return x || y;
}