package com.example.recyclerview;

import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class RecyclerContactAdapter extends RecyclerView.Adapter<RecyclerContactAdapter.ViewHolder>{
    Context context;
    ArrayList<contact> c;


    RecyclerContactAdapter(Context context,ArrayList<contact> d)
    {


        {
            this.context = context;
            this.c = d;
        }
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {

        View v=LayoutInflater.from(context).inflate(R.layout.contact_row,parent,false);
        return new ViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.img.setImageResource(c.get(position).image);
        holder.txt1.setText(c.get(position).name);
        holder.txt2.setText(c.get(position).number);
        holder.llRow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Dialog dialog=new Dialog(context);
                dialog.setContentView(R.layout.add_update);
                EditText edtName=dialog.findViewById(R.id.dialog_contact_name);
                EditText edtNumber=dialog.findViewById(R.id.dialog_contact_number);
                TextView txt=dialog.findViewById(R.id.dialog_heading);
                Button btnAction=dialog.findViewById(R.id.dialog_action);
                txt.setText("Update Contact");
                btnAction.setText("Update");
                edtName.setText((c.get(position)).name);
                edtNumber.setText(c.get(position).number);
                btnAction.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        String name=" ";
                        String number=" ";
                        if(!edtName.getText().toString().equals(" "))
                        {
                            name=edtName.getText().toString();
                        }
                        else
                        {
                            Toast.makeText(context, "There is no Name", Toast.LENGTH_SHORT).show();
                        }
                        if(!edtNumber.getText().toString().equals(" "))
                        {
                            number=edtNumber.getText().toString();
                        }
                        else
                        {
                            Toast.makeText(context, "There is no Number", Toast.LENGTH_SHORT).show();
                        }
                        c.set(position,new contact(R.drawable.baseline_contact_phone_24,name,number));
                        notifyItemChanged(position);

                        dialog.dismiss();

                    }
                });
                dialog.show();
            }
        });

holder.llRow.setOnLongClickListener(new View.OnLongClickListener() {
    @Override
    public boolean onLongClick(View view) {

        AlertDialog.Builder builder=new AlertDialog.Builder(context)
        .setTitle("Delete Contact")
                .setMessage("Are you want to delete")
                .setIcon(R.drawable.baseline_delete_24)
        .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                c.remove(position);
                notifyItemRemoved(position);


            }
        })
                .setNegativeButton("No", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {

                    }
                });
        builder.show();
        return true;
    }
});

    }

    @Override
    public int getItemCount() {
        return c.size();
    }

    public static class ViewHolder  extends RecyclerView.ViewHolder{
        ImageView img;
        TextView txt1,txt2;
        LinearLayout llRow;
        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            img=itemView.findViewById(R.id.rec_img);
            txt1=itemView.findViewById(R.id.contactName);
            txt2=itemView.findViewById(R.id.contactNumber);
            llRow=itemView.findViewById(R.id.ll_row);
        }
    }
}
