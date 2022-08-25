// https://medium.com/analytics-vidhya/convert-word-to-pdf-using-aws-lambda-cb111be0d685
const https = require('https');
const path = require('path');
const fs = require('fs');
var async = require('async');
const {writeFileSync} = require('fs');
const lambdafs = require('lambdafs');
const {execSync} = require('child_process');
var AWS = require('aws-sdk');

const inputPath = path.join( '/opt', 'lo.tar.br');
const outputPath = '/tmp/';
const bucketName = 'document-conversion-aws';

exports.handler = async (event, context) => {
  console.log(execSync('ls -alh /opt').toString('utf8'));

  try {
    // Decompressing
    let decompressed = {
      file: await lambdafs.inflate(inputPath)
    };

    console.log('output brotli de:----', decompressed);
  } catch (error) {
    console.log('Error brotli de:----', error);
  }

  try {
    console.log(execSync('ls -alh /opt').toString('utf8'));
  } catch (e) {
    console.log(e);
  }

  var body = "";
  //S3 put event
  body = event.Records[0].body;
  console.log('s3 bucket file name from event:', body);

  // get file from s3 bucket
  var s3fileName = body;
  var newFileName = Date.now()+'.pdf';
  var s3 = new AWS.S3({apiVersion: '2006-03-01'});
  var fileStream = fs.createWriteStream('/tmp/'+s3fileName);
  var keyFile = "1.docx";
  var getObject = function(keyFile) {
      return new Promise(function(success, reject) {
          s3.getObject(
              { Bucket: "document-conversion-aws", Key: keyFile },
              function (error, data) {
                  if(error) {
                      reject(error);
                  } else {
                      success(data);
                  }
              }
          );
      });
  }

  let fileData = await getObject(s3fileName);
    try{
      fs.writeFileSync('/tmp/'+s3fileName, fileData.Body);
    } catch(err) {
      // An error occurred
      console.error('file write:', err);
    }

    const convertCommand = `export HOME=/tmp && /tmp/lo/instdir/program/soffice.bin --headless --norestore --invisible --nodefault --nofirststartwizard --nolockcheck --nologo --convert-to "pdf:writer_pdf_Export" --outdir /tmp /tmp/${s3fileName}`;
    try {
      console.log(execSync(convertCommand).toString('utf8'));
    } catch (e) {
      console.log(execSync(convertCommand).toString('utf8'));
    }
    console.log(execSync('ls -alh /tmp').toString('utf8'));
    var fileName = "123";
    function uploadFile(buffer, fileName) {
     return new Promise((resolve, reject) => {
      s3.putObject({
       Body: buffer,
       Key: fileName,
       Bucket: bucketName,
      }, (error) => {
       if (error) {
        reject(error);
       } else {

        resolve(fileName);
       }
      });
     });
    }


    let fileParts = s3fileName.substr(0, s3fileName.lastIndexOf(".")) + ".pdf";
    let fileB64data = fs.readFileSync('/tmp/'+fileParts);
    await uploadFile(fileB64data, 'pdf/'+fileParts);
    console.log('new pdf converted and uploaded!!!');
};
