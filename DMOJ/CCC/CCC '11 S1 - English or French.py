n=int(input());
s_count=0
t_count=0
for i in range(n):
  st=input()
  s_count+=st.count('s')+st.count('S')
  t_count+=st.count('t')+st.count('T')

if s_count>=t_count:
  print("French")
else:
  print("English");