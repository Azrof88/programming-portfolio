package com.example.todolist;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.DiffUtil;
import androidx.recyclerview.widget.ListAdapter;
import androidx.recyclerview.widget.RecyclerView;

import com.example.todolist.databinding.ItemoflistBinding;

public class RecyclerViewAdapter extends ListAdapter<Note,RecyclerViewAdapter.ViewHolder> {

    public RecyclerViewAdapter()
    {
        super(CALLBACK);
    }

    private static final DiffUtil.ItemCallback<Note> CALLBACK=new DiffUtil.ItemCallback<Note>() {
        @Override
        public boolean areItemsTheSame(@NonNull Note oldItem, @NonNull Note newItem) {
            return oldItem.getId()== newItem.getId();
        }

        @Override
        public boolean areContentsTheSame(@NonNull Note oldItem, @NonNull Note newItem) {
            return oldItem.getTitle().equals(newItem.getTitle()) && oldItem.getDescription().equals(newItem.getDescription());
        }
    };

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view= LayoutInflater.from(parent.getContext()).inflate(R.layout.itemoflist,parent,false);

        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        Note note=getItem(position);
        holder.binding.titleId.setText(note.getTitle());
        holder.binding.textId.setText(note.getDescription());

    }


    public Note getNote(int position)
    {
        return getItem(position);
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        ItemoflistBinding binding;
        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            binding=ItemoflistBinding.bind(itemView);
        }
    }
}

