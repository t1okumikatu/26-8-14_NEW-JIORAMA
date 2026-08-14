void sankaku(){
  if (direction == 0) {
    if (ctr < 102) ctr++;
    else {
      direction = 1;
    }
  } else {
    if (ctr >= 1) ctr--;
    else {
      direction = 0;
    }
  }
  Serial.println(ctr);
  
}
