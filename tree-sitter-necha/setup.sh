export TS=$(which tree-sitter)

npx nodemon -w ./grammar.js --exec "$TS generate; $TS test"

