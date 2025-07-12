import codecs

#code to create, open and write to a new html file
f = open('GFG.html', 'w')
xvar = 7
html_template = """
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link href="style.css" rel="stylesheet" type="text/css" />
    <script src="index.js" type="text/javascript" defer></script>
  </head>
  <body>
  Time Efficiency Table
  <table>
    <tr>
        <th> </th>
        <th>1 second</th>
    </th>
    <th>
        <th>lg n</th>
        <th>432</th>
"""



# writing the code into the file
f.write(html_template)
  
# close the file
f.close()
  
# viewing html files
# below code creates a 
# codecs.StreamReaderWriter object
file = codecs.open("GFG.html", 'r', "utf-8")
  
# using .read method to view the html 
# code from our object
print(file.read())