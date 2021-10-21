const express = require('express');

const app = express();
const port = process.env.PORT || 8080;

// routes will go here
app.use(express.static('../gui'))

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.post('/api/users', function(req, res) {
  const user_id = req.body.id;
  console.log("test");
  res.send({
    'user_id': user_id
  });
});

app.listen(port);
console.log('Server started at http://localhost:' + port);