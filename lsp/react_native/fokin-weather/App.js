import React from 'react';
import {Alert} from "react-native"
import {API_KEY} from "./config"
import Loading from "./Loading";
import * as Location from 'expo-location';
import axios from "axios";
import Weather from './Weather';

export default class extends React.Component{
  state = {
    isLoading: true
  }
  getWeather = async(latitude, longitude) => {
    const {data} = await axios.get(`http://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&appid=${API_KEY}&units=metric`)
    console.log(data);
    this.setState({isLoading:false,condition: "Clear", temp : data.main.temp})
  }
  getLocation = async() => {
    try{
      await Location.requestPermissionsAsync();
      const { coords: {latitude , longitude} } = await Location.getCurrentPositionAsync();
      this.getWeather(latitude, longitude)
      this.setState({isLoading:false});
      // console.log(coords.latitude, coords.longitude);
    }catch(error){
      Alert.alert("Cant find you ","So sad")
    }

  }
  componentDidMount(){
    this.getLocation();
  }
  render(){
    const { isLoading, temp, condition} = this.state;
    return isLoading ? <Loading /> : <Weather temp={Math.round(temp)} condition={condition}/>;
  }
}
