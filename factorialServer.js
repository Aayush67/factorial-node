const express =  require('express');
const app = express();
var cors = require('cors');
const factorialaddon = require('./build/Release/factorialaddon.node');
app.use(cors());


app.listen(4204, () => {
    console.log("Server started successfully at http://localhost:4204");
    // console.log("aa",factorialaddon.factorial(4));
})
app.get('/getFactorial',(req,res) => {
    var number = req.param('number');
    console.log("Number" ,number);
    var result = factorialaddon.factorial(parseInt(number));
    let data = { factorial : result};
    res.send(data);
})
