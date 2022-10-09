

// Node 14

var AWS = require('aws-sdk');
var iotdata = new AWS.IotData({ endpoint: 'afl1q7n7v0eaz-ats.iot.ap-south-1.amazonaws.com' });

exports.handler = async(event) => {
    console.log("Event => " + JSON.stringify(event));
    if(event.httpMethod === "GET" && event.path === "/iot"){

        let user = {
            status: event.queryStringParameters.ID,
            item: event.queryStringParameters.item,
        };

        var params = {
            topic: "MyTopic",
            payload: JSON.stringify(user),
            qos: 0
        };
    }

    return iotdata.publish(params, function(err, data) {
        if (err) {
            console.log("ERROR => " + JSON.stringify(err));
        }
        else {
            console.log("Success");
        }
    }).promise();
};
