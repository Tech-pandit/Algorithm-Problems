//ITERATIVE POSTORDER TRAVERSAL
void postorder(node *root){
	if(root==null)	
	return ;

	node *temp;
	stack st;

	temp=root;
	while(true){
	   while(temp){
		st.push(temp);
		if(temp->left!=null)
		    temp=temp->left;
		else
		    temp=temp->right;
	   }

	   temp=st.pop();
	   if(!st.is_Empty()){
	   	print(temp->data);
		break;
           }
	   else
	   if(temp == st.top()->left){
		print(temp->data);
		temp=st.top()->right;
	   }
	   else
	   if(temp == st.top()->right){
		print(temp->data);
		temp=null;
	   }
	}
}
