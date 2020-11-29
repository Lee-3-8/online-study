const Sequelize = require('sequelize');

const env = process.env.NODE_ENV || 'development';
const config = require('../config/config')[env];
const Todo = require('./models');
const db = {};

const sequelize = new Sequelize(config.database, config.username, config.password, config);
db.sequelize = sequelize;

db.Todo = Todo;
Todo.init(sequelize);
Todo.associate(db);

module.exports = db;
