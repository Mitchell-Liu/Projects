from openpyxl import load_workbook
from openpyxl.drawing.image import Image
import io
import urllib3

MAX = 2015
workbook = load_workbook(filename="Encounters_Quests_Items_Cells.xlsx")
sheet = workbook.active
http = urllib3.PoolManager()
for i in range(5,MAX):
    name = "B"+str(i)
    try:
        poke_name = sheet[name].value.lower()
        url = "https://img.pokemondb.net/sprites/black-white/normal/" + poke_name +".png"
        r = http.request('GET', url)
        image_file = io.BytesIO(r.data)
        img = Image(image_file)
    except:
        try:
            poke_name = sheet[name].value.lower()
            url = "https://img.pokemondb.net/sprites/x-y/normal/" + poke_name +".png"
            r = http.request('GET', url)
            image_file = io.BytesIO(r.data)
            img = Image(image_file)
        except:
            try:
                poke_name = sheet[name].value.lower()
                url = "https://img.pokemondb.net/sprites/sword-shield/normal/" + poke_name +".png"
                r = http.request('GET', url)
                image_file = io.BytesIO(r.data)
                img = Image(image_file)
            except:
                continue
                
    img.height = 80
    img.width = 80
    poke_img = "C" + str(i)
    sheet.add_image(img, poke_img)
workbook.save(filename="poke.xlsx")