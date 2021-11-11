#!/usr/bin/node

const request = require('request');
const myArg = process.argv.slice(2);
let url = `https://swapi-api.hbtn.io/api/films/${myArg}/`
request.get(url, async (error, response, body) => {
  const characters = JSON.parse(body).characters;
  for (const character of characters) {
    const c = await new Promise((resolve, reject) => {
      request(character, (errori, responsei, bodyi) => {
        if (errori) {
          return console.log(errori)
        } else {
          resolve(JSON.parse(bodyi).name);
        }
      });
    });
    console.log(c);
  }
});
