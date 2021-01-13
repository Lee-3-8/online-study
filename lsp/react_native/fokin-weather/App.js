import { StatusBar } from 'expo-status-bar';
import React from 'react';
import { StyleSheet, Text, View } from 'react-native';

export default function App() {
  return (
    <View style={styles.container}>
      <View style={styles.yellowView}>
        <Text> Hello </Text>
      </View>
    <View style={styles.blueView}>
      <Text>Hello </Text>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: { //모든 공간 사용하게함 
    flex: 1,
    backgroundColor: 'black',
    justifyContent: 'center',

  },
  yellowView: { //레이아웃 나눔 flex : 1 과 flex : 1은 반반 , flex:1 ,2 면 1/3 , 2/3 이런식으로 차지함
    flex:1,
    backgroundColor: 'yellow'
  },
  blueView: {
    flex:1,
    backgroundColor: 'blue'
  }
});
