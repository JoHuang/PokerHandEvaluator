const phe = require('.');
const start = Date.now();
for (let index = 0; index < 5000; index++) {
    phe.evaluate_cards(3, 5, 7 , 8, 9)
    phe.evaluate_cards(3, 5, 7 , 8, 9, 10)
    phe.evaluate_cards(3, 5, 7 , 8, 9, 10, 11)
    phe.evaluate_omaha_cards(3, 5, 7 , 8, 9, 10, 11,13, 14)
}
console.log(`${(Date.now() - start)}`);
