let jnet = require('./json_net.js')

let jserver = new jnet.JSONServer;

jserver.on('json_connection',function(jsocket) {

  jsocket.on('json', function(object) {

      if ( object.command == "ee590" ) {
        jsocket.jwrite({ message: "ok" });

        if ( object.command == "end" ) {
        jsocket.jwrite({ message: "goodbye" });
        jsocket.end();
        }
        else {
        jsocket.jwrite({result: object});
      }
    }

     else {
       jsocket.jwrite({error: "not yet acquainted"});
     }

  });

  jsocket.on('timeout', function() {
    jsocket.jwrite({ message: 'goodbye' });
    jsocket.end();
  });

  jsocket.on('json_error', function(err) {
    jsocket.jwrite({error: err.message});
  });

  jsocket.setTimeout(60*1000);

});

jserver.listen(8080, () => {
  console.log('server bound');
});
