package com.example.recyclerviewpractice;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class RecyclerViewContactAdapter extends RecyclerView.Adapter<RecyclerViewContactAdapter.ViewHolder> {
    Context context;
    ArrayList<contact> arrayContact;
    RecyclerViewContactAdapter(Context context,ArrayList<contact> arrayContact)
    {
        this.context=context;
        this.arrayContact=arrayContact;
    }
    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v= LayoutInflater.from(context).inflate(R.layout.contact_row,parent,false);
        return new ViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.img.setImageResource(arrayContact.get(position).image);
        holder.txtName.setText(arrayContact.get(position).name);
        holder.txtNumber.setText(arrayContact.get(position).number);


    }

    @Override
    public int getItemCount() {
        return arrayContact.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder{
        ImageView img;
        TextView txtName,txtNumber;
        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            img=itemView.findViewById(R.id.rec_img);
            txtName=itemView.findViewById(R.id.contactName);
            txtNumber=itemView.findViewById(R.id.contactNumber);


        }
    }
}
