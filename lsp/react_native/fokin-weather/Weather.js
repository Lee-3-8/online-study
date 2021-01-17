import React from "react";
import { StyleSheet, View, Text } from "react-native"
import { MaterialCommunityIcons } from '@expo/vector-icons';
import PropTypes from "prop-types"

export default function Weather({temp}) {
  return (
  <View style={styles.container}>
    <View style={styles.halfContainer}>
      <MaterialCommunityIcons size = {96} name="weather-rainy"/>
      <Text style= {styles.temp}>{temp}</Text>
    </View>
    <View style={styles.halfContainer}/>
  </View>
  );
}

Weather.propTypes = {
  temp:PropTypes.number.isRequired,
  condition: PropTypes.oneOf(["Thunderstorm" ,"Drizzle","Rain","Snow", "Atmosphere", "Clear","Clouds","Haze","Mist","Dust"]).isRequired
};

const styles = StyleSheet.create({  
  container: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center"
  },
  temp: {
    fontSize:42
  },
  halfContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems:"center"
  }
})