import React from "react";
import { StyleSheet, View, Text, StatusBar } from "react-native";
import { LinearGradient } from 'expo-linear-gradient';
import { MaterialCommunityIcons } from '@expo/vector-icons';
import PropTypes from "prop-types"

const weatherOptions = {
  Haze: {
    iconName: "weather-hail",
    gradient:["#4DA0B0","#D39D38"]
  },
  Thunderstorm: {
    iconName:"",
    gradient:[]
  },
  Drizzle: {
    iconName:"",
    gradient:[]
  },
  Rain: {
    iconName:"",
    gradient:[]
  },
  Snow: {
    iconName:"",
    gradient:[]
  },
  Atmosphere: {
    iconName:"",
    gradient:[]
  },
  Clear: {
    iconName:"",
    gradient:[]
  },
  Clouds: {
    iconName:"",
    gradient:[]
  },
  Haze: {
    iconName:"",
    gradient:[]
  },
  Mist: {
    iconName:"",
    gradient:[]
  },
  Dust: {
    iconName:"",
    gradient:[]
  }

}
export default function Weather({temp, condition}) {
  return (
    <LinearGradient
        // Background Linear Gradient
        colors={weatherOptions[condition].gradient}
        style={styles.container}
    >
      console.log(condition)
      <StatusBar barStyle="light-content"/>  
    <View style={styles.halfContainer}>
      <MaterialCommunityIcons size = {96} name={weatherOptions[condition].iconName} color = "white" />
      <Text style= {styles.temp}>{temp}</Text>
    </View>
    <View style={styles.halfContainer}/>
    </LinearGradient>
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
    fontSize:42,
    color: "white"
  },
  halfContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems:"center"
  }
})