#!/usr/bin/node

const request = require('request');
const myArg = process.argv.slice(2);
const url = `https://swapi-api.hbtn.io/api/films/${myArg}/`;
request.get(url, (error, response, body) => {
    if (error) {
        return console.log(error);
    }
    const characters = JSON.parse(body).characters;
    for (const character of characters) {
        request(character, (errori, responsei, bodyi) => {
            if (error) {
                return console.log(error);
            }
            console.log(JSON.parse(bodyi).name);
        });
    }
});
