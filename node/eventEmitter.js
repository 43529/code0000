var events = require('events');
var eventEmitter = new events.EventEmitter();

var listener1 = function listener1() {
    console.log('listen1执行');
}
var listener2 = function listener2() {
    console.log('listen2执行');
    
}
eventEmitter.addListener('connection', listener1);

eventEmitter.on('connection', listener2);

var eventListeners = eventEmitter.listenerCount('connection');
console.log(eventListeners + "个监听器监听连接事件。");

eventEmitter.emit('connection');

eventEmitter.removeListener('connection', listener1);
console.log('listen1不再受监听');

eventEmitter.emit('connection');

eventListeners = eventEmitter.listenerCount('connection');
console.log(eventListeners + '个监听器监听连接事件');
console.log('程序执行完毕');



