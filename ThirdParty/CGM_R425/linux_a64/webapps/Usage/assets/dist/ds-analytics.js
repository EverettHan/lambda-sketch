!function(e,t){"object"==typeof exports&&"object"==typeof module?module.exports=t():"function"==typeof define&&define.amd?define("DS",[],t):"object"==typeof exports?exports.DS=t():e.DS=t()}("undefined"!=typeof self?self:this,(function(){return function(e){var t={};function n(r){if(t[r])return t[r].exports;var o=t[r]={i:r,l:!1,exports:{}};return e[r].call(o.exports,o,o.exports,n),o.l=!0,o.exports}return n.m=e,n.c=t,n.d=function(e,t,r){n.o(e,t)||Object.defineProperty(e,t,{enumerable:!0,get:r})},n.r=function(e){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},n.t=function(e,t){if(1&t&&(e=n(e)),8&t)return e;if(4&t&&"object"==typeof e&&e&&e.__esModule)return e;var r=Object.create(null);if(n.r(r),Object.defineProperty(r,"default",{enumerable:!0,value:e}),2&t&&"string"!=typeof e)for(var o in e)n.d(r,o,function(t){return e[t]}.bind(null,o));return r},n.n=function(e){var t=e&&e.__esModule?function(){return e.default}:function(){return e};return n.d(t,"a",t),t},n.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},n.p="",n(n.s=3)}([function(e,t,n){var r;void 0===(r=function(){"use strict";function e(e){return null==e?e+"":typeof e}function t(t){return!("object"!==e(t)||t.nodeType||null!=t&&t===t.window)&&!(t.constructor&&!n(t.constructor.prototype,"isPrototypeOf"))}function n(e,t){return null!=e&&hasOwnProperty.call(e,t)}function r(e){return function(){var r,a,i,s,c,u,l=arguments[0]||{},p=1,d=arguments.length,f=!1;for("boolean"==typeof l&&(f=l,l=arguments[p]||{},p++),"object"!=typeof l&&"function"!=typeof l&&(l={});p<d;p++)if(null!=(r=arguments[p]))for(a in r)if(e||n(r,a)){if(i=l[a],l===(s=r[a]))continue;f&&s&&(t(s)||(c=Array.isArray(s)))?(c?(c=!1,u=i&&Array.isArray(i)?i:[]):u=i&&t(i)?i:{},l[a]=o.extend(f,u,s)):void 0!==s&&(l[a]=s)}return l}}var o={assign:r(),extend:r(!0),clone:function(){var t=arguments[0],n=!1;return"boolean"===e(t)&&(n=t,t=arguments[1]),o.extend(n,{},t)},inherit:function(){var e,t=arguments[0],n=arguments[1];return t.prototype=Object.create("function"==typeof n?n.prototype:n),t.prototype.constructor=t,arguments.length>2&&((e=[].slice.call(arguments,2)).unshift(t.prototype),o.assign.apply(null,e)),t}};return o}.call(t,n,t,e))||(e.exports=r)},function(e,t,n){var r;void 0===(r=function(){"use strict";return{counter:{increment:"counter:increment"},timer:{start:"timer:start",stop:"timer:stop"},tracker:{creation:"tracker:creation",update:"tracker:update",getContent:"tracker:get-content",gotContent:"tracker:got-content"},page:{view:"page:view",event:"page:event",interaction:"page:interaction"},data:{register:"data:register"},error:{runtime:"error:runtime",custom:"error:custom"}}}.call(t,n,t,e))||(e.exports=r)},function(e,t,n){var r;void 0===(r=function(){"use strict";return{on:function(e,t){return this.listeners=this.listeners||{},e in this.listeners?this.listeners[e].push(t):this.listeners[e]=[t],this},trigger:function(e){var t=Array.prototype.slice;return this.listeners=this.listeners||{},e in this.listeners&&this.invoke(this.listeners[e],t.call(arguments,1)),"*"in this.listeners&&this.invoke(this.listeners["*"],arguments),this},invoke:function(e,t){for(var n=0,r=e.length;n<r;n++)e[n].apply(this,t)},off:function(e,t){var n;return e in this.listeners&&(t?(n=this.listeners[e].indexOf(t))>=0&&this.listeners[e].splice(n,1):this.listeners[e]=[]),this}}}.call(t,n,t,e))||(e.exports=r)},function(e,t,n){"use strict";n.r(t),n.d(t,"analytics",(function(){return a}));var r=n(4),o=n(9),a={init:function(e){r.init(e),o.init()},trackPageView:o.trackPageView,trackPageEvent:o.trackPageEvent,registerData:o.registerData}},function(e,t,n){var r,o;r=[n(5)],void 0===(o=function(e){return{init:function(){var t;t="string"==typeof arguments[0]?{uploadPath:arguments[0],service:arguments[1],user:arguments[2]}:arguments[0]||{},e.init(t)}}}.apply(t,r))||(e.exports=o)},function(e,t,n){var r,o;r=[n(0),n(6),n(7),n(1),n(8)],void 0===(o=function(e,t,n,r,o){var a,i,s,c,u={themKey:"webapp",user:null,newVisitor:!1},l={scrollable:function(e){return e.clientWidth<e.offsetWidth||"scroll"==e.style.overflowY||"auto"==e.style.overflowY},getAppScrollableContainer:function(e){for(var t,n=e;n;)n.clientHeight<n.scrollHeight&&this.scrollable(n)&&(t=n),n=n.parentNode;return t||document.body},containerHeight:function(e){var t=Math.max(e.scrollHeight,e.offsetHeight,e.clientHeight);return e.getBoundingClientRect().top+t},containerWidth:function(e){var t=Math.max(e.scrollWidth,e.offsetWidth,e.clientWidth);return e.getBoundingClientRect().left+t},viewportTop:function(e){return e.scrollTop},viewportBottom:function(e){return this.viewportTop(e)+(window.innerHeight||document.documentElement.clientHeight||document.body.clientHeight)},viewportLeft:function(e){return e.scrollLeft},viewportRight:function(e){return this.viewportLeft(e)+(window.innerWidth||document.documentElement.clientWidth||document.body.clientWidth)}},p=function(e){var t=e.topic.split(":");return(t=t.length>2?t.slice(0,2):t).join(":")},d={flatten:function(t,n){t[n]&&Array.isArray(t[n])&&(t[n].forEach((function(n){e.extend(t,n)})),delete t[n])},flattenData:function(e){e&&e.data&&["persDimPages","persValPages","persDimPageEvents","persValPageEvents","persDimPageError","persValPageError"].forEach((function(t){d.flatten(e.data,t)}))},parseQuery:function(e){var t=e.substring(e.indexOf("?")+1).split(/[&;]/),n={};return t.length&&t.forEach((function(e){var t=e.indexOf("=")+1,r=t?e.substr(t):"",o=t?e.substr(0,t-1).match(/([^\]\[]+|(\B)(?=\]))/g):[e],a=n;o&&(r=decodeURIComponent(r),o.forEach((function(e,t){e=decodeURIComponent(e);var n=a[e];t<o.length-1?a=a[e]=n||{}:Array.isArray(n)?n.push(r):a[e]=void 0!==n?[n,r]:r})))})),n},parseUrl:(i=["source","subprotocol","protocol","authority","user","password","domain","port","path","directoryPath","fileName","query","anchor"],s=new RegExp("^(?:(?:(?:([^#.:]+):)?([^#.:]+):)?//)?((?:([^:/]+)(?::([^/]*?))?@)?([^:/?#]*)(?::(\\d*))?)?((/(?:[^?#](?![^?#/]*\\.[^?#/.]+(?:[\\?#]|$)))*/?)?([^?#/]*))?(?:\\?([^#]*))?(?:#(.*))?"),function(e){var t,n=s.exec(e),r={};for(t=0;t<i.length;t++)r[i[t]]=n[t]||"";return r.subprotocol&&(r.source=r.source.substr(r.subprotocol.length+1)),r.port||(r.port="https"===r.protocol?"443":"80"),r.directoryPath&&r.directoryPath.length>0&&(r.directoryPath=r.directoryPath.replace(/\/?$/,"/")),r.domain=r.domain.toLocaleLowerCase(),r.protocol=r.protocol.toLocaleLowerCase(),r}),clearData:function(e){e.sessions=[];var t={};e.pages.forEach((function(e){t[e.trackerscope]=e})),t=Object.keys(t).map((function(e){return t[e]})),e.pages=t.sort((function(e,t){return e.timestamp-t.timestamp})),e.interactions=[],e.events=[],e.errors=[]},pruneData:function(e){e.sessions=e.sessions.slice(0,100),e.pages=e.pages.slice(0,100),e.interactions=e.interactions.slice(0,100),e.events=e.events.slice(0,100)},getValidURL:(a=document.createElement("a"),function(e){return a.href=e,a.href}),models:[{internal:"pages",payload:"usage"},{internal:"events",payload:"usage"},{internal:"interactions",payload:"usage"},{internal:"errors",payload:"usage"},{internal:"sessions",payload:"cusage"}],getLastPageID:function(e,t){var n,r=e&&e.pages,o=[];return r&&r.length&&(o=t?r.filter((function(e){return e.trackerscope&&e.trackerscope===t})):r.filter((function(e){return!e.trackerscope}))),(n=o.pop())&&n.id||""},getUTMParameters:function(){var e={},t=d.parseQuery(window.location.search);return t?(["utm_source","utm_medium","utm_campaign","utm_term","utm_content"].forEach((function(n){t.hasOwnProperty(n)&&(e[n]=t[n])})),e):e},getTopDomain:function(){var e,t=d.parseUrl(window.location).domain,n="";if(!/^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$/g.test(t)&&"localhost"!==t){for(e=t.split(".");e.length>2;)e.shift();n=e.join(".")}return n},getConsentsAttributes:function(){var e={};return o.isFunctionalConsent()?e={consent:!0,visitormode:"optin"}:o.hasConsent()?o.hasConsent()&&!o.isFunctionalConsent()&&(e={consent:!0,visitormode:"optout",casUser:"",cookie_vuid:"",user:""}):e={consent:!1,visitormode:"noconsent",casUser:"",cookie_vuid:""},e},getSession:function(n){return n=n||{},e.extend(n,{r_schemaName:"wasession",r_schemaVersion:"1.13",r_service:u.service,r_timestamp:Date.now(),them:u.themKey,sessionID:t.getCookie("_dss"),cookie_vuid:t.getCookie("VUID"),user:t.getCookie("_dsu"),casUser:u.authUser?t.sha256(u.authUser):"",referrer:document.referrer,newVisitor:u.newVisitor,serverhostname:u.hostname,locale:navigator.language||"en-US",enginename:t.clientEngine.name,userAgent:t.clientEngine.userAgent,engineversion:t.clientEngine.version,userAgent:navigator.userAgent,platformname:t.clientPlatform.name,platformmobile:t.clientPlatform.mobile,resheight:t.clientPlatform.resheight,reswidth:t.clientPlatform.reswidth,navigationtype:t.navigationType,startTime:u.navigationStart}),e.extend(n,d.getUTMParameters()),e.extend(n,d.getConsentsAttributes()),n}},f={enableUserInteraction:function(n){var o=n&&n.target,a=o&&l.getAppScrollableContainer(o),i={};if(o&&d.getLastPageID(this)&&("scroll"!==n.type||a===o)){e.extend(i,{interactionid:t.uuid(),action:n.type,viewportTop:l.viewportTop(a),viewportBottom:l.viewportBottom(a),viewportLeft:l.viewportLeft(a),viewportRight:l.viewportRight(a),pageWitdh:l.containerWidth(a),pageHeight:l.containerHeight(a)}),["id","className","tagName"].forEach((function(e){var t=o[e];t&&("string"==typeof t||t instanceof String)&&(i[e]=o[e])})),["clientX","clientY"].forEach((function(e){n[e]&&(i[e]=n[e]),n.touches&&n.touches[0]&&n.touches[0][e]&&(i[e]=n.touches[0][e])}));var s={topic:r.page.interaction,data:i},c={data:JSON.stringify(s)};this.readMessage(c)}},enableErrorTracking:function(e){var t,n={topic:r.error.runtime,data:{}};e.filename&&(n.data.source=e.filename),e.message&&(n.data.message=e.message),e.colno&&(n.data.column=e.colno),e.lineno&&(n.data.line=e.lineno),e.name&&(n.data.name=e.name),e.error&&e.error.name&&(n.data.name=e.error.name),e.stack&&(n.data.stack=e.stack),e.error&&e.error.stack&&(n.data.stack=e.error.stack),Object.keys(n.data).length&&(t={data:JSON.stringify(n)},this.readMessage(t))},enableXHRErrorTracking:(c=0,function(e){var t,n={topic:r.error.runtime,data:{type:"xhr"}};c>10||(e.url&&(n.data.targeturl=e.url),e.message&&(n.data.message=e.message),e.code&&(n.data.code=e.code),e.method&&(n.data.methodurl=e.method),e.duration&&(n.data.duration=e.duration),Object.keys(n.data).length<2||(t={data:JSON.stringify(n)},c+=1,this.readMessage(t)))}),manageCookies:function(){var n,r=t.getCookie("_dsus"),a=t.getCookie("_dsut"),i=d.getTopDomain();r&&t.setCookie("_dss",r,i,u.sessionDuration),a&&t.setPersistantCookie("_dsu",a,i),n=t.getCookie("_dss"),!u.seed&&n||(n=t.uuid(u.seed)),t.setCookie("_dss",n,i,u.sessionDuration),u.user=t.getCookie("_dsu"),u.user?u.newVisitor=!1:(u.user=t.uuid(),u.newVisitor=!0),o.hasConsent()&&!o.isFunctionalConsent()?t.removeCookie("_dsu",i):t.setPersistantCookie("_dsu",u.user,i),u.sessionID!==n&&(u.seed=null,u.navigationStart=Date.now(),u.sessionID=n,d.clearData(this),this.pages.length&&(this.pages=this.pages.map((function(n){return e.extend(n,{id:t.uuid(),sessionID:u.sessionID,browseTime:Date.now()-u.navigationStart,r_timestamp:Date.now(),timestamp:Date.now()})}))),this.sessions.push(d.getSession()),this.send({force:!0}))}};return{sessions:[],pages:[],interactions:[],events:[],errors:[],init:function(){var r,o=this,a=!1;r="string"==typeof arguments[0]?{uploadPath:arguments[0],service:arguments[1],user:arguments[2]}:arguments[0]||{};try{window.top.location.protocol}catch(e){a=!0}a||(e.extend(u,{uploadPath:d.getValidURL(r.uploadPath),sessionDuration:r.sessionDuration||30,sendDebounceRate:r.sendDebounceRate||2500,userActivityThrottleRate:r.userActivityThrottleRate||5e3,userInteractionThrottleRate:r.userInteractionThrottleRate||1e3,userInteractionDebounceRate:r.userInteractionDebounceRate||500,service:r.service,authUser:r.user&&r.user.login||"",hostname:r.hostname||window.location.hostname,themKey:r.them||"webapp",seed:r.seed||null,trackXHRerrors:r.trackXHRerrors||!1,navigationStart:!window.performance||window.performance&&!window.performance.timing?Date.now():window.performance.timing.navigationStart}),window.addEventListener("beforeunload",o.send.bind(o,{mode:"beacon"})),window.addEventListener("message",o.readMessage.bind(o)),window.addEventListener("mousemove",t.throttle(f.manageCookies.bind(o),u.userActivityThrottleRate,!1,!0)),["click","dblclick","contextmenu","touchstart","touchend"].forEach((function(e){window.addEventListener(e,t.throttle(f.enableUserInteraction.bind(o),u.userInteractionThrottleRate,!0),!0)})),["scroll","mousemove","touchmove"].forEach((function(e){window.addEventListener(e,t.debounce(f.enableUserInteraction.bind(o),u.userInteractionDebounceRate),!0)})),window.addEventListener("error",f.enableErrorTracking.bind(o)),u.trackXHRerrors&&n.patch(f.enableXHRErrorTracking.bind(o),u.uploadPath),o.sendDebounced=t.debounce(o.send.bind(o),u.sendDebounceRate),f.manageCookies.call(o))},readMessage:function(n){var o={};try{o=JSON.parse(n.data),d.flattenData(o)}catch(e){}if(!o.forAPI&&o.topic){switch(n.stopPropagation&&n.stopPropagation(),p(o)){case r.page.view:e.extend(o.data,{r_schemaName:"wapage3",r_schemaVersion:"1.10",r_service:u.service,r_timestamp:Date.now(),serverhostname:u.hostname,id:t.uuid(),sessionID:t.getCookie("_dss"),browseTime:Date.now()-u.navigationStart}),o.data.timestamp&&delete o.data.timestamp,this.pages.push(o.data);break;case r.page.event:e.extend(o.data,{r_schemaName:"waevent3",r_schemaVersion:"1.10",r_service:u.service,r_timestamp:Date.now(),id:t.uuid(),sessionID:t.getCookie("_dss"),sessionpageID:d.getLastPageID(this,o.data.trackerscope)}),o.data.timestamp&&delete o.data.timestamp,this.events.push(o.data);break;case r.page.interaction:e.extend(o.data,{r_schemaName:"wainteraction3",r_schemaVersion:"1.08",r_service:u.service,r_timestamp:Date.now(),sessionID:t.getCookie("_dss"),sessionpageID:d.getLastPageID(this)}),this.interactions.push(o.data);break;case r.data.register:e.extend(o.data,{r_schemaName:"wasession",r_schemaVersion:"1.13",r_service:u.service,r_timestamp:Date.now(),sessionID:t.getCookie("_dss")}),e.extend(o.data,d.getConsentsAttributes()),this.sessions.push(o.data);break;case r.error.runtime:e.extend(o.data,{r_schemaName:"waerror3",r_schemaVersion:"1.14",r_service:u.service,r_timestamp:Date.now(),id:t.uuid(),sessionID:t.getCookie("_dss"),sessionpageID:d.getLastPageID(this),level:"error",category:"runtime"}),this.errors.push(o.data);break;case r.error.custom:e.extend(o.data,{r_schemaName:"waerror3",r_schemaVersion:"1.14",r_service:u.service,r_timestamp:Date.now(),id:t.uuid(),sessionID:t.getCookie("_dss"),sessionpageID:d.getLastPageID(this),category:"custom"}),this.errors.push(o.data)}d.pruneData(this),o.sync?this.send():this.sendDebounced()}},send:function(e){var n,r=new FormData,a=e&&e.mode||"xhr",i=this,s=0;d.models.forEach((function(e){i[e.internal].forEach((function(t){r.append(e.payload+s,JSON.stringify(t)),s++}))})),s&&((!o.hasConsent()||o.isFunctionalConsent()||e&&e.force)&&("beacon"===a?navigator.sendBeacon?navigator.sendBeacon(u.uploadPath,r):t.beaconPolyfill(u.uploadPath,r):((n=new XMLHttpRequest).open("POST",u.uploadPath),n.send(r))),d.clearData(this))}}}.apply(t,r))||(e.exports=o)},function(e,t,n){var r;void 0===(r=function(){"use strict";function e(e){return"xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx".replace(/[xy]/g,(function(t){var n,r=16*(e?(n=1e4*Math.sin(e++))-Math.floor(n):Math.random())|0;return("x"===t?r:3&r|8).toString(16)}))}var t,n,r,o,a,i,s,c={uuid:e,getUUID:e,navigationType:(s="unknown",window.performance.navigation&&(s=0===(i=window.performance.navigation.type)?"navigate":1===i?"reload":2===i?"back":"unknown"),s),getChecksum:function(){var e=arguments,t=String(e[0]),n=e[1],r=0,o=t.length;for(n=n||305419896;r<o;r++)n+=t.charCodeAt(r)*r;return Math.abs(parseInt(n,10)).toString(36)},beaconPolyfill:function(e,t){var n=window.XMLHttpRequest?new XMLHttpRequest:new window.ActiveXObject("Msxml2.XMLHTTP");n.open("POST",e,!1),n.setRequestHeader("Content-Type","text/plain;charset=UTF-8"),n.setRequestHeader("Accept","*/*"),n.send(t)},clientEngine:(a=navigator.userAgent?navigator.userAgent.toLowerCase():"","ie"===(t=a.match(/(opera|ie|firefox|chrome|version)[\s\/:]([\w\d\.]+)?.*?(safari|version[\s\/:]([\w\d\.]+)|$)/)||a.match(/(webkit)[\s\/:]([\w\d\.]+)/)||a.match(/(trident)\/.*rv:([\d\.]+)/))[1]||"trident"===t[1]?(o=(n=window.document&&document.documentMode)&&n.toString(),r="ie"):(o="opera"===t[1]&&t[4]?t[4]:t[2],r="version"===t[1]?t[3]:t[1]),{name:r,version:o,userAgent:a}),clientPlatform:function(){var e=navigator&&navigator.userAgent.toLowerCase()||"",t=(navigator&&navigator.platform.toLowerCase()||"").split(" ")[0],n=/ip(?:ad|od|hone)/.test(e)?"ios":/webos|wossystem/.test(e)?"webos":/blackberry/.test(e)?"blackberry":/android/.test(e)?"android":/mac|win|linux/.test(t)?t:"other";return{name:n,mobile:"ios"===n||"android"===n||"blackberry"===n||!!e.match(/tablet/),resheight:screen&&screen.height||0,reswidth:screen&&screen.width||0}}(),isVirtualKeyboardOpen:function(){var e=function(){try{return top.document.documentElement}catch(e){return document.documentElement}}(),t={},n=!1,r=e.clientHeight,o=window.screen.height;function a(){if(!c.clientPlatform.mobile||"ios"===c.clientPlatform.name)return!1;var o=i(),a=t[o];if(t[o]=Math.max(t[o]||0,e.clientHeight),!a||e.clientHeight===r)return n;r=e.clientHeight}function i(){return window.screen.width+"x"+window.screen.height}return setTimeout(a),window.addEventListener("resize",(function(){r===e.clientHeight?setTimeout((function e(){if(window.screen.height===o)return setTimeout(e,250);a(),o=window.screen.height}),250):a()})),function(){return n=e.clientHeight<t[i()]}}(),copy:function(e){var t,n,r,o=e.contentEditable,a=e.readOnly;return"ios"===this.clientPlatform.name?(e.contentEditable=!0,e.readOnly=!0,(t=document.createRange()).selectNodeContents(e),(n=window.getSelection()).removeAllRanges(),n.addRange(t),e.setSelectionRange(0,e.value.length),e.contentEditable=o,e.readOnly=a):e.select(),r=document.execCommand("copy"),e.blur(),r},getCookie:function(e){var t,n,r=[];try{r=document.cookie.split("; ")}catch(e){}return(t=r.filter((function(t){return t.split("=")[0]===e}))).length&&(n=t[0].split("=")[1]),n},setPersistantCookie:function(e,t,n){var r,o=new Date;o.setFullYear(o.getFullYear()+1),r=e+"="+t+"; expires="+o.toUTCString(),n&&(r+="; domain="+n+"; path=/"),document.cookie=r},setCookie:function(e,t,n,r){var o=new Date(Date.now()+6e4*r),a=e+"="+t;n&&(a+="; domain="+n+"; path=/"),r&&(a+="; expires="+o.toUTCString()),document.cookie=a},removeCookie:function(e,t){var n;n=e+"=undef; expires="+new Date(0).toUTCString(),t&&(n+="; domain="+t+"; path=/"),document.cookie=n},debounce:function(e,t,n){var r;return function(){var o,a=this,i=arguments,s=function(){r=null,n||e.apply(a,i)};o=n&&!r,clearTimeout(r),r=setTimeout(s,t),o&&e.apply(a,i)}},throttle:function(e,t,n,r,o){var a,i,s,c=null,u=0,l=function(){u=new Date,c=null,s=e.apply(a,i)};return function(){var p=new Date;u||n||(u=p);var d=t-(p-u);return a=o||this,i=arguments,d<=0?(clearTimeout(c),c=null,u=p,s=e.apply(a,i)):!c&&r&&(c=setTimeout(l,d)),s}},sha256:function e(t){function n(e,t){return e>>>t|e<<32-t}for(var r,o,a=Math.pow,i=a(2,32),s="",c=[],u=8*t.length,l=e.h=e.h||[],p=e.k=e.k||[],d=p.length,f={},h=2;d<64;h++)if(!f[h]){for(r=0;r<313;r+=h)f[r]=h;l[d]=a(h,.5)*i|0,p[d++]=a(h,1/3)*i|0}for(t+="";t.length%64-56;)t+="\0";for(r=0;r<t.length;r++){if((o=t.charCodeAt(r))>>8)return;c[r>>2]|=o<<(3-r)%4*8}for(c[c.length]=u/i|0,c[c.length]=u,o=0;o<c.length;){var g=c.slice(o,o+=16),m=l;for(l=l.slice(0,8),r=0;r<64;r++){var v=g[r-15],y=g[r-2],w=l[0],b=l[4],k=l[7]+(n(b,6)^n(b,11)^n(b,25))+(b&l[5]^~b&l[6])+p[r]+(g[r]=r<16?g[r]:g[r-16]+(n(v,7)^n(v,18)^v>>>3)+g[r-7]+(n(y,17)^n(y,19)^y>>>10)|0);(l=[k+((n(w,2)^n(w,13)^n(w,22))+(w&l[1]^w&l[2]^l[1]&l[2]))|0].concat(l))[4]=l[4]+k|0}for(r=0;r<8;r++)l[r]=l[r]+m[r]|0}for(r=0;r<8;r++)for(o=3;o+1;o--){var D=l[r]>>8*o&255;s+=(D<16?0:"")+D.toString(16)}return s}};return c}.call(t,n,t,e))||(e.exports=r)},function(e,t,n){var r;void 0===(r=function(){return{patch:function(e,t){XMLHttpRequest.prototype.__open||XMLHttpRequest.prototype.__send||(XMLHttpRequest.prototype.__open=XMLHttpRequest.prototype.open,XMLHttpRequest.prototype.open=function(e,t){this.method=e,this.url=t,this.__open.apply(this,arguments)},XMLHttpRequest.prototype.__send=XMLHttpRequest.prototype.send,XMLHttpRequest.prototype.send=function(){this.time=Date.now(),this.__onreadystatechange=this.onreadystatechange,this.onreadystatechange=function(n){try{var r=n&&n.currentTarget||{status:0,statusText:"",responseText:""};if(r.status>=400&&!this._tracked&&!this.url.startsWith(t)){var o=Date.now()-this.time;e({url:r.url,code:r.status,method:r.method,duration:o,message:r.responseText||r.statusText}),this._tracked=!0}}catch(e){}finally{this.__onreadystatechange&&this.__onreadystatechange.apply(this,arguments)}},this.onerror=function(n){try{var r=n&&n.currentTarget||{status:0,statusText:"",responseText:""};if(!this._tracked&&!this.url.startsWith(t)){var o=Date.now()-this.time;e({url:r.url,code:r.status,method:r.method,duration:o,message:r.responseText||r.statusText}),this._tracked=!0}}catch(e){}},this.__send.apply(this,arguments)})}}}.apply(t,[]))||(e.exports=r)},function(e,t,n){var r;void 0===(r=function(){"use strict";Number.isInteger||(Number.isInteger=function(e){return"number"==typeof e&&isFinite(e)&&Math.floor(e)===e});var e=["status","privacyVersion","consentCategories","blockedOnCategories","creationTimestamp"],t=["necessary","functional","advertising"],n={getCookie:function(e){var t,n,r=[];try{r=document.cookie.split("; ")}catch(e){}return(t=r.filter((function(t){return t.split("=")[0]===e}))).length&&(n=t[0].split("=")[1]),n},getIndexFromRank:function(e){if(e=parseInt(e),Number.isInteger(e))return e-1;throw new Error("GDPR : Cookie rank must be an integer")},decode:function(e,r){var o=r.includes("%2C")?r.split("%2C"):r;if("consentCategories"===e)if(r)if(Array.isArray(o))o=o.map((function(e){var r=n.getIndexFromRank(e);return t[r]}));else{var a=n.getIndexFromRank(r);o=a?[t[a]]:o}else o=[t[0]];return o},getModel:function(){var t=n.getCookie("TC_PRIVACY"),r=t&&t.split("@")||[],o={status:0,privacyVersion:"001",consentCategories:[],blockedOnCategories:1,creationTimestamp:Date.now()};return r.forEach((function(t,r){var a=e[r];o[a]=n.decode(a,t)})),o}};return{get:n.getModel,getConsentCategories:function(){return this.get().consentCategories},isFunctionalConsent:function(){return this.getConsentCategories().includes(t[1])},hasConsent:function(){return!!this.getConsentCategories().length}}}.call(t,n,t,e))||(e.exports=r)},function(e,t,n){var r,o;r=[n(0),n(2),n(10),n(1)],void 0===(o=function(e,t,n,r){"use strict";var o=!1,a=function(){var e=window.location,t=window.top.location;try{t.protocol}catch(e){o=!0}return o?{}:{current:e.protocol+"//"+e.hostname+(e.port?":"+e.port:""),parent:t.protocol+"//"+t.hostname+(t.port?":"+t.port:"")}}(),i=window.top;function s(e){return"string"==typeof e||e instanceof String}function c(e){return"number"==typeof e&&isFinite(e)}function u(e){return e&&"object"==typeof e&&e.constructor===Object}function l(e){return"function"==typeof e}function p(e){var t=!0;if(!u(e))return!1;if(0==Object.keys(e).length)return!1;if(Object.keys(e).length>20)return!1;for(var n in e)e.hasOwnProperty(n)&&(/^(pd|pv)[0-9]+$/.test(n)||(t=!1),s(e[n])||(t=!1));return t}function d(e){var t=!0;if(!u(e))return!1;if(0==Object.keys(e).length)return!1;if(Object.keys(e).length>20)return!1;for(var n in e)e.hasOwnProperty(n)&&(/^(pd|pv)[0-9]+$/.test(n)||(t=!1),c(e[n])||(t=!1));return t}var f={getTracker:function(){var t,o,a=arguments,i=a[0],s=a[1],c=a[2];if(void 0===c&&"object"==typeof s?(c=s,s=i,i="action"):void 0===c&&"string"==typeof s?c={}:void 0===s&&void 0===c&&("string"==typeof i?(s=i,i="action",c={}):(s=(o=e.clone(i)).name,i=o.type,c=o.options||{})),void 0===s)throw new TypeError("No tracker name specified");switch(i){case"action":var u=c;u.name=s,this.notify(u,r.tracker.creation),t=new n(s)}return t},trackPageView:function(e,t,n,c,f){var h=arguments[0];if(u(h)&&(e=h.pageURL,t=h.pageTitle,n=h.persDim,c=h.pageLanguage,f={persVal:h.persVal,appID:h.appID,tenant:h.tenant,scope:h.scope}),!o&&e&&s(e)){var g={origin:a.current,topic:r.page.view,sync:!!h.callback,data:{url:e,location:window.location.href,timestamp:Date.now(),pagelg:c||(window.dsLang?window.dsLang:"")}};t&&s(t)&&(g.data.title=t),n&&p(n)&&(g.data.persDimPages=[n]),f&&u(f)&&d(f.persVal)&&(g.data.persValPages=[f.persVal]),f&&u(f)&&f.appID&&(g.data.appID=f.appID),f&&u(f)&&f.tenant&&(g.data.tenant=f.tenant),f&&u(f)&&s(f.scope)&&(g.data.trackerscope=f.scope),i.postMessage&&i.postMessage(JSON.stringify(g),a.parent),l(h.callback)&&setTimeout(h.callback,0)}},trackPageEvent:function(e,t,n,f,h,g){var m=arguments[0];if(u(m)&&(e=m.eventCategory,t=m.eventAction,n=m.eventLabel,f=m.eventValue,h=m.persDim,g={persVal:m.persVal,appID:m.appID,tenant:m.tenant,scope:m.scope}),!o&&e&&s(e)&&t&&s(t)){var v={origin:a.current,topic:r.page.event,sync:!!m.callback,data:{category:e,action:t,timestamp:Date.now()}};n&&s(n)&&(v.data.label=n),f&&c(f)&&(v.data.value=f),h&&p(h)&&(v.data.persDimPageEvents=[h]),g&&u(g)&&d(g.persVal)&&(v.data.persValPageEvents=[g.persVal]),g&&u(g)&&g.appID&&(v.data.appID=g.appID),g&&u(g)&&g.tenant&&(v.data.tenant=g.tenant),g&&u(g)&&s(g.scope)&&(v.data.trackerscope=g.scope),i.postMessage&&i.postMessage(JSON.stringify(v),a.parent),l(m.callback)&&setTimeout(m.callback,0)}},trackPageError:function(e,t,n,c,f,h){var g=arguments[0];if(u(g)&&(e=g.errorLevel,t=g.errorMessage,n=g.errorName,c=g.errorSource,f=g.persDim,h={persVal:g.persVal,errorSourceColumn:g.errorSourceColumn,errorSourceLine:g.errorSourceLine,errorStack:g.errorStack,errorCode:g.errorCode,errorType:g.errorType,errorTargetUrl:g.errorTargetUrl,errorMethodUrl:g.errorMethodUrl,errorDuration:g.errorDuration,appID:g.appID,scope:g.scope,tenant:g.tenant}),!o&&e&&s(e)&&t&&s(t)&&n&&s(n)&&c&&s(c)){var m={origin:a.current,topic:r.error.custom,sync:!!g.callback,data:{level:e,message:t,name:n,source:c,timestamp:Date.now()}};h&&u(h)&&h.errorSourceColumn&&(m.data.column=h.errorSourceColumn),h&&u(h)&&h.errorSourceLine&&(m.data.line=h.errorSourceLine),h&&u(h)&&h.errorStack&&(m.data.stack=h.errorStack),h&&u(h)&&h.errorCode&&(m.data.code=h.errorCode),h&&u(h)&&h.errorType&&(m.data.type=h.errorType),h&&u(h)&&h.errorTargetUrl&&(m.data.targeturl=h.errorTargetUrl),h&&u(h)&&h.errorMethodUrl&&(m.data.methodurl=h.errorMethodUrl),h&&u(h)&&h.errorDuration&&(m.data.duration=h.errorDuration),h&&u(h)&&h.appID&&(m.data.appID=h.appID),h&&u(h)&&s(h.scope)&&(m.data.trackerscope=h.scope),f&&p(f)&&(m.data.persDimPageError=[f]),h&&u(h)&&d(h.persVal)&&(m.data.persValPageError=[h.persVal]),h&&u(h)&&h.tenant&&(m.data.tenant=h.tenant),i.postMessage&&i.postMessage(JSON.stringify(m),a.parent),l(g.callback)&&setTimeout(g.callback,0)}},registerData:function(){var e,t,n=arguments;!o&&n.length&&(1===n.length&&"object"==typeof n[0]?e=n[0]:n.length>1&&((e={})[n[0]]=n[1]),e&&(t={origin:a.current,topic:r.data.register,data:e},i.postMessage&&i.postMessage(JSON.stringify(t),a.parent)))},notify:function(e,t){if(!o){var n={origin:a.current,topic:t,data:e};i.postMessage&&i.postMessage(JSON.stringify(n),a.parent)}},init:function(){if(!o){var n=this;this._initiated||(this._initiated=!0,t.on("*",(function(t,r){r.forAPI||n.notify(e.clone(r),t)})),window.addEventListener("message",(function(e){var n={};try{n=JSON.parse(e.data)}catch(e){}n.forAPI&&(e.stopPropagation(),t.trigger(n.topic,n))})))}}};return f.init(),f}.apply(t,r))||(e.exports=o)},function(e,t,n){var r,o;r=[n(0),n(11),n(13)],void 0===(o=function(e,t,n){"use strict";function r(e){n.warn("Module DS/Usage/ActionTracker is deprecated. Use DS/Usage/TrackerAPI#trackPageEvent instead"),t.call(this,e),this.type="action"}return e.inherit(r,t),r}.apply(t,r))||(e.exports=o)},function(e,t,n){var r,o;r=[n(0),n(12),n(2),n(1)],void 0===(o=function(e,t,n,r){"use strict";function o(e){this.name=e}return e.inherit(o,{set:function(e,t){var o;"object"==typeof e?(o=e,t=void 0):(o={})[e]=t,Object.keys(o).length>0&&(o.name=this.name,o.type=this.type,n.trigger(r.tracker.update,o))},get:function(){var e=this;return new t((function(t){var o=r.tracker.gotContent+":"+e.name,a=r.tracker.getContent+":"+e.name;n.on(o,(function(r){n.off(o),r&&r.data&&r.data.name===e.name&&t(r.data)})),n.trigger(a,{name:e.name})}))}}),o}.apply(t,r))||(e.exports=o)},function(e,t,n){var r;!function(o){"use strict";void 0===(r=function(){function e(e){return null==e?e+"":typeof e}var t,n=o.Promise,r=n&&"resolve"in n&&"reject"in n&&"all"in n&&"race"in n&&function(){var e;return new n((function(t){e=t})),"function"==typeof e}(),a=void 0!==o.setImmediate?o.setImmediate:o.setTimeout,i=[];function s(){for(var e=0;e<i.length;e++)i[e][0](i[e][1]);i=[],t=!1}function c(e,n){i.push([e,n]),t||(t=!0,a(s,0))}function u(e){var t=e._then;e._then=void 0;for(var n=0;n<t.length;n++)m(t[n])}function l(e){e._state="fulfilled",u(e)}function p(e){e._state="rejected",u(e)}function d(e,t){"pending"===e._state&&(e._state="sealed",e._data=t,c(l,e))}function f(e,t){e!==t&&g(e,t)||d(e,t)}function h(e,t){"pending"===e._state&&(e._state="sealed",e._data=t,c(p,e))}function g(t,n){var r;try{if(t===n)throw new TypeError("A promises callback cannot return that same promise.");if(n&&("function"===e(n)||"object"===e(n))){var o=n.then;if("function"===e(o))return o.call(n,(function(e){r||(r=!0,n!==e?f(t,e):d(t,e))}),(function(e){r||(r=!0,h(t,e))})),!0}}catch(e){return r||h(t,e),!0}return!1}function m(t){var n=t.owner,r=n._state,o=n._data,a=t[r],i=t.then;if("function"===e(a)){r="fulfilled";try{o=a(o)}catch(e){h(i,e)}}g(i,o)||("fulfilled"===r&&f(i,o),"rejected"===r&&h(i,o))}function v(t){if("function"!==e(t))throw new TypeError("Promise constructor takes a function argument");if(this instanceof v==="false")throw new TypeError("Failed to construct 'Promise': Please use the 'new' operator, this object constructor cannot be called as a function.");this._then=[],function(e,t){function n(e){h(t,e)}try{e((function(e){f(t,e)}),n)}catch(e){n(e)}}(t,this)}return v.prototype={constructor:v,_state:"pending",_then:null,_data:void 0,then:function(e,t){var n={owner:this,then:new this.constructor((function(){})),fulfilled:e,rejected:t};return"fulfilled"===this._state||"rejected"===this._state?c(m,n):this._then.push(n),n.then},catch:function(e){return this.then(null,e)}},v.all=function(t){if(!Array.isArray(t))throw new TypeError("You must pass an array to Promise.all().");return new this((function(n,r){var o=[],a=0;function i(e){return a++,function(t){o[e]=t,--a||n(o)}}for(var s,c=0;c<t.length;c++)(s=t[c])&&"function"===e(s.then)?s.then(i(c),r):o[c]=s;a||n(o)}))},v.race=function(t){if(!Array.isArray(t))throw new TypeError("You must pass an array to Promise.race().");return new this((function(n,r){for(var o,a=0;a<t.length;a++)(o=t[a])&&"function"===e(o.then)?o.then(n,r):n(o)}))},v.resolve=function(t){return t&&"object"===e(t)&&t.constructor===this?t:new this((function(e){e(t)}))},v.reject=function(e){return new this((function(t,n){n(e)}))},r?n:v}.call(t,n,t,e))||(e.exports=r)}(this)},function(e,t,n){var r;/*! Copyright 2015 Dassault Systèmes */void 0===(r=function(){"use strict";var e=Array.prototype.slice,t=Function.prototype.apply,n=function(n,r){return function(){"undefined"!=typeof console&&console[n]?t.call(console[n],console,e.call(arguments)):r&&r.apply(r,e.call(arguments))}},r={};return r.log=n("log"),r.info=n("info",r.log),r.debug=n("debug",r.log),r.warn=n("warn",r.log),r.error=n("error",r.log),r.trace=n("trace",(function(){r.log((new Error).stack)})),r}.call(t,n,t,e))||(e.exports=r)}])}));
