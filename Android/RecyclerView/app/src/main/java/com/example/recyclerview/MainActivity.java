package com.example.recyclerview;

import android.app.Dialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
RecyclerView recyclerView;
FloatingActionButton btnOpenDialog;
    RecyclerContactAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        recyclerView=findViewById(R.id.recyclerview);
        btnOpenDialog=findViewById(R.id.rec_btn);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        ArrayList<contact> arrayNum=new ArrayList<>();


        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.b,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));
        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,"Azrof","01748123469"));

adapter=new RecyclerContactAdapter(this,arrayNum);
        recyclerView.setAdapter(adapter);
        btnOpenDialog.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Dialog dialog=new Dialog(MainActivity.this);
                dialog.setContentView(R.layout.add_update);
                EditText edtName=dialog.findViewById(R.id.dialog_contact_name);
                EditText edtNumber=dialog.findViewById(R.id.dialog_contact_number);
                Button btnAction=dialog.findViewById(R.id.dialog_action);
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
                            Toast.makeText(MainActivity.this, "There is no Name", Toast.LENGTH_SHORT).show();
                        }
                        if(!edtNumber.getText().toString().equals(" "))
                        {
                            number=edtNumber.getText().toString();
                        }
                        else
                        {
                            Toast.makeText(MainActivity.this, "There is no Number", Toast.LENGTH_SHORT).show();
                        }
                        arrayNum.add(new contact(R.drawable.baseline_contact_phone_24,name,number));
                        adapter.notifyItemInserted(arrayNum.size()-1);
                        recyclerView.scrollToPosition(arrayNum.size()-1);
dialog.dismiss();
                    }
                });
                dialog.show();
            }
        });



    }
}