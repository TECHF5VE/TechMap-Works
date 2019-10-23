var trans = document.getElementById('trans')
var a = document.getElementsByClassName('Card_content1')[0]
var b = document.getElementsByClassName('Card_content')[0]
trans.onmouseover = function() {
  a.style.margin = 50 + 'px' + ' ' + 30 + 'px'
  a.style.display = 'block'
  b.style.display = 'none'
}
trans.onmouseout = function() {
  a.style.margin = 50 + 'px' + ' ' + 530 + 'px'
  a.style.display = 'none'
  b.style.display = 'block'
}
