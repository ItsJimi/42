var hash = require('mhash');

module.exports = {
	passHash : function(mail, pass) {
		return (hash("whirlpool", mail + pass));
	}
};
