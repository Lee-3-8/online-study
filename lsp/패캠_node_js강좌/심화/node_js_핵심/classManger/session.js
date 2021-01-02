'use strict'

const CacheManager = require('./cache');

class sessionManager extends cacheManager {

}

const SessionManager = new sessionManager();
SessionManager.addConfig({token : 'ran'});
