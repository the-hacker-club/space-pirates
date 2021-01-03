var express = require('express')
var router = express.Router()

/* GET users listing. */
router.get('/greeting', function (req, res, next) {
  let msg = { msg: "Space Pirates!" }
  res.json(msg).end()
})

module.exports = router
