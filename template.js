const lines = [];

const helpers = {
  arrStringtoInt: (arr, splitter) => {
    return arr.split(splitter).map(num => parseInt(num));
  },
  insterAt: (arr, idx, item) => {
    const newArray = [...arr];
    newArray.splice(idx, 0, item);
    return newArray;
  },
  sortAscending: (arr) => {
    return arr.sort((a, b) => a - b);
  },
  sortDescending(arr) {
    return arr.sort((a, b) => b - a);
  }
}

const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

// multi line input
readline.on('line', line => {
  lines.push(line);
});

readline.on('close', line => {
  const matchs = [];
  let total = 0;

  for (let x = 1; x < lines.length; x++) {
    const m = helpers.arrStringtoInt(lines[x], ' ');
    matchs.push(m);
  }


  // [ [1,2], [2,4], [3,4]  ]

  let n = matchs.length;


  for (let y = 0; y < n; y++) {

    for (let x = 0; x < n; x++) {
      if (y != x) {
        if(matchs[y][0] == matchs[x][1]) {
          total++;
        }
      }
    }
  }


  console.log(total)



});
 