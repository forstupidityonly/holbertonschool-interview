#!/usr/bin/node

const request = require('request');
const myArg = process.argv.slice(2);
const url = `https://swapi-api.hbtn.io/api/films/${myArg}/`;
request.get(url, (error, response, body) => {
    if (error) {
        return console.log(error);
    }
    const characters = JSON.parse(body).characters;
    const charDict = {};
    for (const character of characters) {
        request(character, (errori, responsei, bodyi) => {
            if (error) {
                return console.log(error);
            }
            charDict[character] = JSON.parse(bodyi).name;
            if (Object.values(charDict).length === characters.length) {
                for (const i in characters) {
                    console.log(charDict[i]);
                }
            }
        });
    }
});
