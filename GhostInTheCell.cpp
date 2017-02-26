#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
struct Factory {   
        int id;
        int owner;
        int population;
        int production;        
        
 };
 
 struct Troop {      
        int id;
        int owner;
        int origin;
        int target;        
        int population;
        int remaining;
 };
 
vector<Factory> factories;
vector<Troop> troops;
vector<vector<int> > distances;

int neutrals = 0;
int enemies = 0;

bool by_id (Factory i,Factory j) { return (i.id<j.id); }

int closest( int origin_id, int target_owner){
    int min = 20;
    int id = origin_id;
    for( auto it : factories){
        if (distances[origin_id][it.id] < min && origin_id != it.id && it.owner == target_owner){
            id = it.id;
            min = distances[origin_id][it.id];
        }            
    }
    return id;
}

int biggest(int origin_owner){
    int max = 0;
    int id = 0;
    for( auto it : factories){
        if ( it.population > max && it.owner == origin_owner){
            id = it.id;
            max = it.population;
        }            
    }
    return id;
}

int main()
{
    int factoryCount; // the number of factories
    cin >> factoryCount; cin.ignore();
    int linkCount; // the number of links between factories
    cin >> linkCount; cin.ignore();
    

    distances.resize(factoryCount);
    for (int i = 0; i < factoryCount; i++) 
        distances[i].resize(factoryCount);    
    
    for (int i = 0; i < linkCount; i++) {
        int factory1;
        int factory2;
        int distance;
        cin >> factory1 >> factory2 >> distance; cin.ignore();
        distances[factory1][factory2] = distance;
        distances[factory2][factory1] = distance;
    }
    
    // for (int i = 0; i < factoryCount; i++) {
    //     cerr << i << ":" << endl;
    //     sort(distances[i].begin(), distances[i].end());
    //     for( auto it : distances[i])
    //         cerr << "   " << it << endl;
    // }
    // game loop
        
    while (1) {
        int entityCount; // the number of entities (e.g. factories and troops)
        cin >> entityCount; cin.ignore();
        
        for (int i = 0; i < entityCount; i++) {
            int entityId;
            string entityType;
            int arg1;
            int arg2;
            int arg3;
            int arg4;
            int arg5;
            cin >> entityId >> entityType >> arg1 >> arg2 >> arg3 >> arg4 >> arg5; cin.ignore();
            
            if(entityType == "FACTORY"){
                Factory f;
                f.id = entityId;
                f.owner = arg1;
                f.population = arg2;
                f.production = arg3;
                factories.push_back(f);      
                
                if (f.owner == 0) neutrals++;
                if (f.owner == -1) enemies++;
            }
            
            if(entityType == "TROOP"){
                Troop t;
                t.id = entityId;
                t.owner = arg1;
                t.origin = arg2;
                t.target = arg3;
                t.population = arg4;
                t.remaining = arg5;
                troops.push_back(t);
            }
                            
        }
        
        sort(factories.begin(), factories.end(), by_id);
        for( auto it : factories){
            cerr << "Factory :" << it.id << ", owner: " << it.owner << endl;
        }
        
        if ( neutrals > 0) {   
            int bf = biggest(1);
            int cf = closest(bf, 0);
            cerr << "Factory :" << bf << ", target: " << cf << ", owner: " << factories[cf].owner << endl;
            cout << "MOVE " << bf << " " << cf << " " << factories[cf].population + 1 << endl;         
            
                
        }        
        else if ( enemies > 0) {   
            int bf = biggest(1);
            int cf = closest(bf, -1);
            cout << "MOVE " << bf << " " << cf << " " << factories[cf].population + 1 << endl;    
                       
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Any valid action, such as "WAIT" or "MOVE source destination cyborgs"
        else
            cout << "WAIT" << endl;
            
        factories.clear();
        troops.clear();
        
        neutrals = 0;
        enemies = 0;
        
    }
    distances.clear();
}
