// Copyright 2017 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

'use strict';

// [START gae_node_request_example]
const express = require('express');
var url = require('url');
var q="";
const app = express();

app.get('/', (req, res) => {
  res.status(200).send('Hello, world!').end();
q = url.parse(req.url, true); 
if(q.search!=null){

dataa.quote=q.search.split('=')[0].substring(1); 
dataa.author=q.search.split('=')[1]; 
db.collection('mohamed').doc('glaoui')
	.set(dataa).then(() => 
	console.log('new Dialogue written to database'));
}

});
const serviceAccount = require('./serviceAccountKey.json');
const admin = require('firebase-admin');
//initialize admin SDK using serciceAcountKey
admin.initializeApp({
	credential: admin.credential.cert(serviceAccount)
});
const db = admin.firestore();
var http = require('https');
var url = require('url');
var dataa={"quote":"",
	"author":""
	};


// Start the server
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
  console.log(`App listening on port ${PORT}`);
  console.log('Press Ctrl+C to quit.');
});
// [END gae_node_request_example]

module.exports = app;
