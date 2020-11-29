const Sequelize = require('sequelize');

module.exports = class User extends Sequelize.Model {
  static init(sequelize) {
    return super.init({
      ko_text: {
        type: Sequelize.STRING(1000),
        allowNull: false,
      },
      en_text: {
        type: Sequelize.STRING(1000),
        allowNull: false,
      },
      time: {
        type: Sequelize.NOW,
        allowNull: false,
      },
    }, {
      sequelize,
      timestamps: false,
      underscored: false,
      modelName: 'todo',
      tableName: 'todo',
      paranoid: false,
      charset: 'utf8',
      collate: 'utf8_general_ci',
    });
  }
  static associate(db) {}
};