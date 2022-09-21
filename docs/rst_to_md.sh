FILES=*.rst
for f in $FILES
do
  filename="${f%.*}"
  echo "Converting $f to ../doc/singlehtml/$filename.md"
  `pandoc $f -f rst -t markdown -o ../doc/singlehtml/$filename.md`
done
