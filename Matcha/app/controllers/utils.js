var lwip = require('lwip');
var validator = require('validator');
var db = require('./database.js');

module.exports = {
	img: function(picture, size, type, callback) {
        var encondedImageBuffer = new Buffer(picture, 'base64');
        lwip.open(encondedImageBuffer, type, function(err, image) {
            if (err) {
                console.log(err);
            } else {
                image.batch().cover(size, size).toBuffer('png', function(e, buffer) {
                    if (e)
                        console.log(e);
					else
                        callback(buffer);
                });
            }
        });
    },
	getPeoplesNear: function(username, distance, callback, opts) {
		if (!distance || distance == '')
        	distance = 1000000;
        //arg: distance in km, converted for mongo in rad
        db.get("profiles", function(me) {
            if (me[0].pos) {

                var std = {
                    pos: {
                        $nearSphere: me[0].pos,
                        $maxDistance: distance / 6371
                    },
                    username: {
                        $ne: username
                    }
                };

                Object.assign(std, opts);

				var users = [];
				var block = [];
				var i = 0;

				db.get("block", function(data) {
					if (data.length > 0) {
						data.forEach(function(user) {
							block.push(user.users[1]);
							i++;
						});
						db.get("profiles", function(data) {
							data.forEach(function(profile) {
								profile.filter = 0;

								if (block.indexOf(profile.username) == -1 && profile.img) {
									if (module.exports.getAgeFromProfile(profile) <= (module.exports.getAgeFromProfile(me[0]) + 5) && module.exports.getAgeFromProfile(profile) >= (module.exports.getAgeFromProfile(me[0]) - 5))
										profile.filter += 5;
									if (profile.tags) {
										profile.tags.forEach(function(tag) {
											if (me[0].tags) {
												me[0].tags.forEach(function(filterTag) {
													if (tag === filterTag)
														profile.filter += 4;
												});
											}
										});
									}

									if (me[0].preference === "Both" && me[0].gender === "Man") {
										if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
											users.push(profile);
										else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
											users.push(profile);
									}
									else if (me[0].preference === "Man" && me[0].gender === "Man") {
										if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
											users.push(profile);
									}
									else if (me[0].preference === "Woman" && me[0].gender === "Man") {
										if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
											users.push(profile);
									}
									else if (me[0].preference === "Both" && me[0].gender === "Woman") {
										if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
											users.push(profile);
										else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
											users.push(profile);
									}
									else if (me[0].preference === "Woman" && me[0].gender === "Woman") {
										if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
											users.push(profile);
									}
									else if (me[0].preference === "Man" && me[0].gender === "Woman") {
										if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
											users.push(profile);
									}
									if (profile.gender === "Unknown" || me[0].gender === "Unknown")
										users.push(profile);
								}
							});
							callback(users);
						}, std);
					}
					else {
						db.get("profiles", function(data) {
							data.forEach(function(profile) {
								profile.filter = 0;

								if (module.exports.getAgeFromProfile(profile) <= (module.exports.getAgeFromProfile(me[0]) + 5) && module.exports.getAgeFromProfile(profile) >= (module.exports.getAgeFromProfile(me[0]) - 5))
									profile.filter += 5;
								if (profile.tags) {
									profile.tags.forEach(function(tag) {
										if (me[0].tags) {
											me[0].tags.forEach(function(filterTag) {
												if (tag === filterTag)
													profile.filter += 4;
											});
										}
									});
								}

								if (me[0].preference === "Both" && me[0].gender === "Man") {
									if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
										users.push(profile);
									else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
										users.push(profile);
								}
								else if (me[0].preference === "Man" && me[0].gender === "Man") {
									if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
										users.push(profile);
								}
								else if (me[0].preference === "Woman" && me[0].gender === "Man") {
									if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
										users.push(profile);
								}
								else if (me[0].preference === "Both" && me[0].gender === "Woman") {
									if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
										users.push(profile);
									else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
										users.push(profile);
								}
								else if (me[0].preference === "Woman" && me[0].gender === "Woman") {
									if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
										users.push(profile);
								}
								else if (me[0].preference === "Man" && me[0].gender === "Woman") {
									if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
										users.push(profile);
								}
								if (profile.gender === "Unknown" || me[0].gender === "Unknown")
									users.push(profile);
							});
							callback(users);
						}, std);
					}
				}, {
					'users.0': validator.escape(username)
				});
            }
			else {
                callback(null);
            }
        }, {
			username: validator.escape(username)
		});
    },
	getPeoplesNearFilters: function(username, distance, filters, callback, opts) {
		if (!distance || distance == '' || distance < 0)
        	distance = 1000000;
        //arg: distance in km, converted for mongo in rad
        db.get("profiles", function(me) {
            if (me[0].pos) {
                var std = {
                    pos: {
                        $nearSphere: me[0].pos,
                        $maxDistance: distance / 6371
                    },
                    username: {
                        $ne: username
                    }
                };

                Object.assign(std, opts);

				var users = [];
				var block = [];
				var i = 0;

				db.get("block", function(data) {
					if (data.length > 0) {
						data.forEach(function(user) {
							block.push(user.users[1]);
							i++;
						});
						db.get("profiles", function(data) {
							var tags = [];

							if (filters.tags) {
								filters.tags.forEach(function(tag) {
									tags.push(tag);
								});
							}
							data.forEach(function(profile) {
								profile.filter = 0;

								if (block.indexOf(profile.username) == -1 && profile.img) {
									if (module.exports.getAgeFromProfile(profile) <= filters.age_max && module.exports.getAgeFromProfile(profile) >= filters.age_min) {
										if (profile.score <= filters.score_max && profile.score >= filters.score_min) {
											if (profile.tags) {
												var i = 0;

												profile.tags.forEach(function(tag) {
													if (tags.indexOf(tag) != -1)
														i++;
												});
												if (i == tags.length || filters.tags.length == 0) {
													if (me[0].preference === "Both" && me[0].gender === "Man") {
														if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
															users.push(profile);
														else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
															users.push(profile);
													}
													else if (me[0].preference === "Man" && me[0].gender === "Man") {
														if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
															users.push(profile);
													}
													else if (me[0].preference === "Woman" && me[0].gender === "Man") {
														if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
															users.push(profile);
													}
													else if (me[0].preference === "Both" && me[0].gender === "Woman") {
														if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
															users.push(profile);
														else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
															users.push(profile);
													}
													else if (me[0].preference === "Woman" && me[0].gender === "Woman") {
														if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
															users.push(profile);
													}
													else if (me[0].preference === "Man" && me[0].gender === "Woman") {
														if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
															users.push(profile);
													}
													if (profile.gender === "Unknown" || me[0].gender === "Unknown")
														users.push(profile);
												}
											}
										}
									}
								}
							});
							callback(users);
						}, std);
					}
					else {
						db.get("profiles", function(data) {
							var tags = [];

							if (filters.tags) {
								filters.tags.forEach(function(tag) {
									tags.push(tag);
								});
							}
							data.forEach(function(profile) {
								profile.filter = 0;

								if (module.exports.getAgeFromProfile(profile) <= filters.age_max && module.exports.getAgeFromProfile(profile) >= filters.age_min) {
									if (profile.score <= filters.score_max && profile.score >= filters.score_min) {
										if (profile.tags) {
											var i = 0;

											profile.tags.forEach(function(tag) {
												if (tags.indexOf(tag) != -1)
													i++;
											});
											if (i == tags.length || filters.tags.length == 0) {
												if (me[0].preference === "Both" && me[0].gender === "Man") {
													if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
														users.push(profile);
													else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
														users.push(profile);
												}
												else if (me[0].preference === "Man" && me[0].gender === "Man") {
													if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Man"))
														users.push(profile);
												}
												else if (me[0].preference === "Woman" && me[0].gender === "Man") {
													if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Man"))
														users.push(profile);
												}
												else if (me[0].preference === "Both" && me[0].gender === "Woman") {
													if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
														users.push(profile);
													else if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
														users.push(profile);
												}
												else if (me[0].preference === "Woman" && me[0].gender === "Woman") {
													if (profile.gender === "Woman" && (profile.preference === "Both" || profile.preference === "Woman"))
														users.push(profile);
												}
												else if (me[0].preference === "Man" && me[0].gender === "Woman") {
													if (profile.gender === "Man" && (profile.preference === "Both" || profile.preference === "Woman"))
														users.push(profile);
												}
												if (profile.gender === "Unknown" || me[0].gender === "Unknown")
													users.push(profile);
											}
										}
									}
								}
							});
							callback(users);
						}, std);
					}
				}, {
					'users.0': validator.escape(username)
				});
            }
			else {
                callback(null);
            }
        }, {
			username: validator.escape(username)
		});
    },
	getAgeFromProfile: function(profile) {
		if (!profile.birthdate) {
			return 0;
		}
		var ageDifMs = Date.now() - (new Date(profile.birthdate));
		var ageDate = new Date(ageDifMs); // miliseconds from epoch
		return Math.abs(ageDate.getUTCFullYear() - 1970);
	}
};
