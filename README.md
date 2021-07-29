# LoRaRosserial

UI_SampleData.ino:
目前是利用Serial進行傳輸，封包一開始會有"S"字元，隨後會有24個Bytes的資料，分別是x、y、a變數，皆是Double型態，最後會有"E"做為結尾
