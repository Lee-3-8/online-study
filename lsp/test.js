const testNone = () => {
  let test = 0;
  for(i=0;i<10000;i++){
    test = i;
    console.log(i);
  }
  console.log('None');
}

async function test() {
  console.log('teststart');
  await testNone();
  console.log('testend');
}

test();