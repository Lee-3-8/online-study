'use strict'

// const numbers = [10, 20, 30, 40]

// //reduce를 사용하게 된다면 각 배열의 요소를 접근가능 , 가독성이 높아짐

// const avg = numbers.reduce((tot , val ,idx , arr) => {
//   tot += val
//   if (idx === arr.length - 1) {
//     return tot/arr.length
//   } else {
//     return tot
//   }
// });

// console.log(avg)

const arr = ['pdf', 'html', 'html', 'gif', 'gif', 'gif']

// const res = numbers.reduce((tot, amt) => {
//   if (amt > 0) tot.push(amt)
//   return tot
// }, []) //두번째 파라미터 []로 tot가 초기화된다.

// console.log(res)

const res = arr.reduce((cnt, fileType) => {
  cnt[fileType] = (cnt[fileType] || 0) + 1 //cnt[fileType]에서 undefined가 나오는것을 방지
  return cnt
}, {})

console.log(res)